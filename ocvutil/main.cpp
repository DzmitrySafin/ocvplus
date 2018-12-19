#include <iostream>
#include <windows.h>
#include "resource.h"
#include "CoreApi.hpp"

void LoadEmbeddedImage(cv::Mat& image, int resourceId)
{
    const HBITMAP hBitmap = ::LoadBitmap(::GetModuleHandle(nullptr), MAKEINTRESOURCE(resourceId));

    BITMAP bitmap;
    ::GetObject(hBitmap, sizeof(BITMAP), &bitmap);
    image.create(bitmap.bmWidth, bitmap.bmHeight, CV_8UC4);

    BITMAPINFOHEADER bmpinfo;
    memset(&bmpinfo, 0, sizeof(BITMAPINFOHEADER));
    bmpinfo.biSize = sizeof(BITMAPINFOHEADER);
    bmpinfo.biWidth = bitmap.bmWidth;
    bmpinfo.biHeight = -bitmap.bmHeight;
    bmpinfo.biPlanes = bitmap.bmPlanes;
    bmpinfo.biBitCount = bitmap.bmBitsPixel;

    const HDC hdc = GetDC(nullptr);
    ::GetDIBits(hdc, hBitmap, 0, bmpinfo.biHeight, image.data, reinterpret_cast<BITMAPINFO*>(&bmpinfo), DIB_RGB_COLORS);
    ::ReleaseDC(nullptr, hdc);

    ::DeleteObject(hBitmap);
}

int main(int argc, const char * argv[])
{
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::cout << "OpenCV version: " << CCoreApi::OpencvVersion() << std::endl;

    cv::Mat imgOriginal;
    LoadEmbeddedImage(imgOriginal, IDB_BITMAP_CUBE);

    cv::Mat imgGray;
    cv::cvtColor(imgOriginal, imgGray, cv::COLOR_BGR2GRAY);

    cv::namedWindow("window");
    cv::imshow("window", imgGray);
    cv::waitKey();
    cv::destroyWindow("window");

    return 0;
}
