#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Mat rotation(Mat original, double angle)
{
    Mat rotate;
    Point2f pt(original.cols / 2., original.rows / 2.);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(original, rotate, r, Size(original.cols, original.rows));
    return rotate;
}

int main()
{
    Mat original = imread("image.jpg");

    //resize(original, original, Size(), 0.3, 0.3, INTER_LINEAR);

    Mat rotate;
    double angle;
    cout << "Enter Angle you want to rotate this: ";
    cin >> angle;
    rotate = rotation(original, angle);

    imshow("Original Image", original);
    imshow("Rotated Image", rotate);
    waitKey(0);
    return 0;
}