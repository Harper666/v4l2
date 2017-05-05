#include "dialog.h"
#include <QApplication>
//#include <opencv2/opencv.hpp>
#include "v4l2_init.h"
#include <stdio.h>
#include <unistd.h>//包含了close函数
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>  //包含了open函数
#include <linux/videodev2.h>
#include <malloc.h>
#include <sys/mman.h>
#include <iostream>
#include <stdio.h>

//cv::Mat QImage2cvMat(QImage image);

struct buffer
{
    void *start;
    int len;
};

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog w;
    w.show();

    int fd;
    fd_set fds;
    struct buffer buffers;

    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    fd = open(argv[1],O_RDWR| O_NONBLOCK);

    FD_ZERO(&fds);
    FD_SET(fd,&fds);

    v4l2_init(fd);

    int ret = select(fd+1,&fds,NULL,NULL,&tv);
    if(ret == 0)
    {
        printf("erro:select timeout \n");
        return 0;
    }
    if(ret == -1)
    {
        printf("erro \n");
        return 0;
    }

    buffers = v4l2_getImage(fd);

    QImage image;
    image.loadFromData((uchar*)buffers.start, buffers.len);

//    cv::Mat mat = QImage2cvMat(image);
//    cv::imshow("【原图】", mat);

    w.showImage(image);

    return a.exec();
}


//cv::Mat QImage2cvMat(QImage image)
//{
//    cv::Mat mat;
//    qDebug() << image.format();
//    switch(image.format())
//    {
//    case QImage::Format_ARGB32:
//    case QImage::Format_RGB32:
//    case QImage::Format_ARGB32_Premultiplied:
//        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
//        break;
//    case QImage::Format_RGB888:
//        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
//        cv::cvtColor(mat, mat, CV_BGR2RGB);
//        break;
//    case QImage::Format_Indexed8:
//        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
//        break;
//    }
//    return mat;
//}
