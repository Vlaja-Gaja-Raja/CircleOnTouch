#pragma once

#include <vector>

#include <opencv2\imgproc\imgproc.hpp>

class ISquaresDetection
{
public:
	virtual ~ISquaresDetection(){}
	
	virtual cv::Mat GetSquare(int row, int col) const = 0;

	virtual bool IsEmpty(int row, int col) = 0;
	virtual bool IsDetected() = 0;

	virtual std::vector<cv::Mat> getImageSquares() = 0;
};