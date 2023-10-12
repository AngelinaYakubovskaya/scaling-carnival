#include <fstream>
#include <iostream>

using namespace std;

#pragma pack(1)
struct BITMAPFILEHEADER {
    int16_t bfType;
    int32_t bfSize;
    int16_t bfReserved1;
    int16_t bfReserved2;
    int32_t bfOffBits;
};

struct BITMAPINFOHEADER {
    int32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    int16_t biPlanes;
    int16_t biBitCount;
    int32_t biCompression;
    int32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    int32_t biClrUsed;
    int32_t biClrImportant;
};
#pragma pack()

void turnRight(char* inputBuffer, char* outputBuffer, int width, int height,
    int sizeOfPixel) {

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            const int newIndex = ((width - i - 1) * height + j) * sizeOfPixel;
            const int oldIndex = (j * width + i) * sizeOfPixel;

            for (int k = 0; k < sizeOfPixel; ++k) {
                outputBuffer[newIndex + k] = inputBuffer[oldIndex + k];
            }
        }
    }
}

void turnLeft(char* inputBuffer, char* outputBuffer, int width, int height,
    int sizeOfPixel) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            const int newIndex = ((height - i - 1) + j * height) * sizeOfPixel;
            const int oldIndex = (i * width + j) * sizeOfPixel;

            for (int k = 0; k < sizeOfPixel; ++k) {
                outputBuffer[newIndex + k] = inputBuffer[oldIndex + k];
            }
        }
    }
}

void applyGaussianFilter(char* inputBuffer, char* outputBuffer, int width,
    int height, int sizeOfPixel) {
    // Gaussian kernel for a 5x5 filter
    int kernel[5][5] = { {1, 2, 4, 2, 1},
                        {2, 4, 8, 4, 2},
                        {4, 8, 16, 8, 4},
                        {2, 4, 8, 4, 2},
                        {1, 2, 4, 2, 1} };

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int totalR = 0, totalG = 0, totalB = 0;
            int divisor = 0;

            for (int ky = -2; ky <= 2; ++ky) {
                for (int kx = -2; kx <= 2; ++kx) {
                    int posX = x + kx;
                    int posY = y + ky;

                    if (posX >= 0 && posX < width && posY >= 0 && posY < height) {
                        int index = (posY * width + posX) * sizeOfPixel;
                        totalR += inputBuffer[index] * kernel[ky + 2][kx + 2];
                        totalG += inputBuffer[index + 1] * kernel[ky + 2][kx + 2];
                        totalB += inputBuffer[index + 2] * kernel[ky + 2][kx + 2];
                        divisor += kernel[ky + 2][kx + 2];
                    }
                }
            }

            int index = (y * width + x) * sizeOfPixel;
            outputBuffer[index] = totalR / divisor;
            outputBuffer[index + 1] = totalG / divisor;
            outputBuffer[index + 2] = totalB / divisor;

            if (sizeOfPixel * 8 == 32) {
                outputBuffer[index + 3] = inputBuffer[index + 3]; // Alpha channel
            }
        }
    }
}

void writeBuffer(const char* file, ifstream& is, BITMAPINFOHEADER bmpInfoHeader,
    char* buffer, int bufferSize, int sizeOfPixel, int shiftToData,
    bool isHeadChanged = true) {
    ofstream os(file, ofstream::binary);
    if (!os) {
        cerr << "Output file is unvalid" << endl;
        return;
    }

    is.seekg(0, is.beg);
    os << is.rdbuf();

    if (isHeadChanged) {
        os.seekp(sizeof(BITMAPFILEHEADER));
        os.write(reinterpret_cast<char*>(&bmpInfoHeader),
            sizeof(BITMAPINFOHEADER));
    }

    os.seekp(shiftToData); // Перемещаем указатель к началу пиксельных данных
    os.write(buffer, bufferSize *
        sizeOfPixel); // Записывает данные размером newBufferSize
    // байт из буфера newBuffer в поток os
    os.close();

    delete[] buffer;
}

int main() {
    ifstream is("Mandrill.bmp", ifstream::binary);

    if (!is) {
        cerr << "File can't be opened!"
            << endl; // Выводит сообщение об ошибке в стандартный поток ошибок
        return 1;
    }

    BITMAPFILEHEADER bmpHeader;
    is.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BITMAPFILEHEADER));
    const int length = bmpHeader.bfSize;
    cout << "Count of memory for image: " << length << "B" << endl;

    is.seekg(sizeof(BITMAPFILEHEADER));
    BITMAPINFOHEADER bmpInfoHeader;
    is.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(BITMAPINFOHEADER));
    int width = bmpInfoHeader.biWidth;
    int height = bmpInfoHeader.biHeight;

    // Читаем пиксели из исходного файла и поворачиваем изображение
    int bufferSize = width * height;
    int sizeOfPixel = bmpInfoHeader.biBitCount / 8; // Длина пикселя в байтах
    char* buffer = new char[sizeOfPixel * bufferSize];
    const int shiftToData = bmpHeader.bfOffBits;

    is.seekg(shiftToData); // Перемещаем указатель к началу пиксельных данных (байт 54)
    is.read(buffer, bufferSize * sizeOfPixel);

    // Создаем новый буфер для повернутого изображения
    bmpInfoHeader.biWidth = height;
    bmpInfoHeader.biHeight = width;

    // write to gauss file -----------------------------
    char* bufferGauss = new char[sizeOfPixel * bufferSize];
    applyGaussianFilter(buffer, bufferGauss, width, height, sizeOfPixel);
    writeBuffer("Gauss.bmp", is, bmpInfoHeader, bufferGauss, bufferSize,
        sizeOfPixel, shiftToData, false);

    // write to right file -----------------------------
    char* rightTransformBuffer = new char[sizeOfPixel * bufferSize];
    turnRight(buffer, rightTransformBuffer, width, height, sizeOfPixel);
    writeBuffer("Rotated1.bmp", is, bmpInfoHeader, rightTransformBuffer,
        bufferSize, sizeOfPixel, shiftToData);

    // write to left file -----------------------------
    char* leftTransformBuffer = new char[sizeOfPixel * bufferSize];
    turnLeft(buffer, leftTransformBuffer, width, height, sizeOfPixel);
    writeBuffer("Rotated2.bmp", is, bmpInfoHeader, leftTransformBuffer,
        bufferSize, sizeOfPixel, shiftToData);

    is.close();
    delete[] buffer;

    cout << "Success!!!" << endl;
    return 0;
}
