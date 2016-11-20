//
// Created by Vlatko on 11/19/2016.
//

#include <jni.h>
#include <cwchar>
#include <vector>

#include "../../../../sudoku_c++/ISquaresDetection.h"
#include "../../../../sudoku_c++/SquaresDetection.h"

using namespace std;

extern "C"

void Java_com_example_vlatko_sudokusolver_SquaresDetection_formImageSquares (
        JNIEnv *env,
        jobject obj
)
{
    jclass jClass_SquaresDetection =  env->FindClass("com/example/vlatko/sudokusolver/SquaresDetection");
    jobject jObject_SquaresDetection = env->AllocObject(jClass_SquaresDetection);

    jfieldID jfieldID_mImage = env->GetFieldID(jClass_SquaresDetection, "mImage", "org/opencv/core/Mat");
    jfieldID jfieldID_mSquares = env->GetFieldID(jClass_SquaresDetection, "mSquares", "Ljava/util/ArrayList");
    jfieldID jfieldID_mEmptySquares = env->GetFieldID(jClass_SquaresDetection, "mSquares", "[[Z");

    //to get the field values
    //env->GetObjectField(jobject, jfieldID);

    //to set value
    //env->SetObjectField(jobject, jfieldID, jobject);

    //napravi omotac za arrayList metodu add
    //napravi omotac za Mat metodu add get NativeObjAddr a mozad bi mogao ovo u java metodi

    jobject arrayListObject;
    jclass arrayListClass;

    jfieldID fieldID = env->GetFieldID(jClass_SquaresDetection, "mSquares", "Ljava/util/ArrayList");
    if ( fieldID != NULL){
        arrayListClass = env->FindClass("java/util/List");

        arrayListObject = env->AllocObject(arrayListClass);
    }

    jlong addrGray;
    Mat& java_image  = *(Mat*)mGray.getNativeObjAddr();
    ISquaresDetection * b = new SquaresDetection(java_image);
    
    if (b->IsDetected()){
        vector<Mat> imageSquares = b->getImageSquares();
        mSquares<-imageSquares;
    }

}

void Java_com_example_vlatko_sudokusolver_SquaresDetection_formEmptySquares (
        JNIEnv *env,
        jobject obj
)
{

}