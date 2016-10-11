#include "Source.h"

	// �J�����̓����p�����[�^�A�c�݌W���̓ǂݍ���
	DLLExport void loadCameraParam(double projectionMatrix[], double dist[])
    {
		cv::Mat cameraMat(3, 3, CV_64F);
		cv::Mat distMat(1, 5, CV_64F);

		cv::FileStorage cvfs("Calibration/calibration.xml", CV_STORAGE_READ);
		cvfs["cam_K"] >> cameraMat;
		cvfs["cam_dist"] >> distMat;

		for(int i = 0; i < 9; ++i)
		{
			projectionMatrix[i] = cameraMat.at<double>(i);
		}
		for(int i = 0; i < 5; ++i)
		{
			dist[i] = distMat.at<double>(i);
		}
	}

	// �v���W�F�N�^�̓����p�����[�^�A�c�݌W���̓ǂݍ���
	DLLExport void loadProjectorParam(double projectionMatrix[], double dist[])
    {
		cv::Mat cameraMat(3, 3, CV_64F);
		cv::Mat distMat(1, 5, CV_64F);

		cv::FileStorage cvfs("Calibration/calibration.xml", CV_STORAGE_READ);
		cvfs["proj_K"] >> cameraMat;
		cvfs["proj_dist"] >> distMat;

		for(int i = 0; i < 9; ++i)
		{
			projectionMatrix[i] = cameraMat.at<double>(i);
		}
		for(int i = 0; i < 5; ++i)
		{
			dist[i] = distMat.at<double>(i);
		}
	}

	// �O���p�����[�^(�v���W�F�N�^�̃J�����ɑ΂���)�̓ǂݍ���
	DLLExport void loadExternalParam(double R[], double T[])
    {
		cv::Mat r(3, 3, CV_64F);
		cv::Mat t(3, 1, CV_64F);

		cv::FileStorage cvfs("Calibration/calibration.xml", CV_STORAGE_READ);
		cvfs["R"] >> r;
		cvfs["T"] >> t;

		for(int i = 0; i < 9; ++i)
		{
			R[i] = r.at<double>(i);
		}
		for(int i = 0; i < 3; ++i)
		{
			T[i] = t.at<double>(i);
		}
	}
