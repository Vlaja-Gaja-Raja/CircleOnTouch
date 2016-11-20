#pragma once
#include <string>
#include <vector>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class ISquaresDetection;

class SquaresDetection : public ISquaresDetection{
public:
	SquaresDetection(std::string filename);
	SquaresDetection(cv::Mat image);

	cv::Mat GetSquare(int row, int col) const override;
	
	bool IsEmpty(int row, int col) override;
	bool IsDetected() override;
	std::vector<cv::Mat> getImageSquares() override;
private:
	void imagePreProcessing(cv::Mat& image);

	cv::Rect getBiggestRectangle();
	
	cv::Point topLeftCorner(std::vector<cv::Point> contours);
	int SquaresHeight(std::vector<cv::Point> contours);
	int SquaresWidth(std::vector<cv::Point> contours);
	double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
	bool IsRectangle(std::vector<cv::Point> contours);

	cv::Mat m_image;
	std::vector<cv::Mat> m_allFields;
};
