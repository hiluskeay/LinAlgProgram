#include <iostream>

//Vector Class
class VectorR3{
    public:
        VectorR3();
        VectorR3(double arr[3]);
        VectorR3(double v1, double v2, double v3);
        ~VectorR3();
        double getv1();
        double getv2();
        double getv3();



        //Overloads:
        VectorR3 operator = (double arr[3]);
        // + to add
        VectorR3 operator + (VectorR3 &V1);
        // - to subtract
        VectorR3 operator - (VectorR3 &V1);
        // * to dot product
        double operator * (VectorR3 &V1);
        // / to cross product
        VectorR3 operator / (VectorR3 &V1);

        void print();
    
    private:
        double vector[3]{};

};

//Vector Member Function Definitions

VectorR3::VectorR3(){
     vector[0] = 0;
    vector[1] = 0;
    vector[2] = 0;
}

VectorR3::VectorR3(double arr[3]){
    vector[0] = arr[0];
    vector[1] = arr[1];
    vector[2] = arr[2];
}

VectorR3::VectorR3(double v1, double v2, double v3){
    vector[0] = v1;
    vector[1] = v2;
    vector[2] = v3;
}

VectorR3::~VectorR3(){
    for (int i; i < 3; i++){
        vector[i] = 0;
    }
}

double VectorR3::getv1(){
    return vector[0];
}

double VectorR3::getv2(){
    return vector[1];
}

double VectorR3::getv3(){
    return vector[2];
}

VectorR3 VectorR3::operator = (double arr[3]){
    vector[0] = arr[0];
    vector[1] = arr[1];
    vector[2] = arr[2];

}

VectorR3 VectorR3::operator + (VectorR3 &V1){

    VectorR3 Temp{0,0,0};
    double temp[3]{0,0,0};

    temp[0] = vector[0] + V1.getv1();
    temp[1] = vector[1] + V1.getv2();
    temp[2] = vector[2] + V1.getv3();

    Temp = temp;
    return Temp;
    
}

VectorR3 VectorR3::operator - (VectorR3 &V1){

    VectorR3 Temp{0,0,0};
    double temp[3]{0,0,0};

    temp[0] = vector[0] - V1.getv1();
    temp[1] = vector[1] - V1.getv2();
    temp[2] = vector[2] - V1.getv3();

    Temp = temp;
    return Temp;
    
}

double VectorR3::operator * (VectorR3 &V1){
    double temp{};

    temp = ((vector[0]*V1.getv1())+(vector[1]*V1.getv2())+(vector[2]*V1.getv3()));

    return temp;
}

VectorR3 VectorR3::operator / (VectorR3 &V1){

    VectorR3 Temp{};
    double temp[3]{};

    temp[0] = ((vector[1]*V1.getv3())-(V1.getv2()*vector[2]));
    temp[1] = ((vector[2]*V1.getv1())-(V1.getv3()*vector[0]));
    temp[2] = ((vector[0]*V1.getv2())-(V1.getv1()*vector[1]));

    Temp = temp;
    return Temp;


}

void VectorR3::print(){
    std::cout << "[" ;
    std::cout << vector[0] << ", ";
    std::cout << vector[1] << ", ";
    std::cout << vector[2] ;
    std::cout << "]";
    std::cout << std::endl;
}

//Matrix Class
class Matrix3x3{
    public:

    Matrix3x3();
    Matrix3x3(double arr[9]);
    Matrix3x3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33);
    Matrix3x3(VectorR3 V1, VectorR3 V2, VectorR3 V3);
    ~Matrix3x3();

    private:

        double matrix[9]{};
};

Matrix3x3::Matrix3x3(){
    for (int i{}; i < 8; i++){
        matrix[i] = 0;
    }
}

Matrix3x3::Matrix3x3(double arr[9]){
    for (int i{}; i < 8; i++){
        matrix[i] = arr[i];
    }
}

Matrix3x3::Matrix3x3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33){

}

Matrix3x3::Matrix3x3(VectorR3 V1, VectorR3 V2, VectorR3 V3){

}


//Set Class
class Set{

};

int main();

int main(){

    VectorR3 V1{1,2,3};
    VectorR3 V2{7,18,9};
    VectorR3 V3{};

    V1.print();
    V2.print();

    double dot{V1*V2};

    std::cout << dot << std::endl;

    V3 = V1/V2;

    V3.print();

    return 0;
}