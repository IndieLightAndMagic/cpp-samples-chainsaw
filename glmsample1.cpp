#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat2x3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <functional>
#include <iostream>



namespace GTech {

    class Camera;
    class CameraConfiguration{
        float   aspectRatioW { 16.0f };
        float   aspectRatioH { 9.0f };
        float   nearClippingPlane { 0.1f };
        float   farClippingPlane { 100.0f };
        float   fovy{ glm::radians(45.0f) };
        bool    isDirty{true};

    public:
        void SetAspectRatioW( const float& ratio){
            aspectRatioW = ratio;
            isDirty = true;
        }
        void SetAspectRatioH( const float& ratio){
            aspectRatioH = ratio;
            isDirty = true;
        }
        float GetAspectRatio() const{
            return aspectRatioW / aspectRatioH;
        }
        float GetAspectRatioW() const{
            return aspectRatioW;
        }
        float GetAspectRatioH() const{
            return aspectRatioH;
        }

        float GetFarClippingPlane() const {
            return farClippingPlane;
        }
        float GetNearClippingPlane() const {
            return nearClippingPlane;
        }

        void SetFarClippingPlane(const float& farClippingPlane) {
            CameraConfiguration::farClippingPlane = farClippingPlane;
            isDirty = true;
        }
        void SetNearClippingPlane(const float& nearClippingPlane) {
            CameraConfiguration::farClippingPlane = nearClippingPlane;
            isDirty = true;
        }

        float GetFovy() const {
            return fovy;
        }

        void SetFovy(const float& fovy) {
            CameraConfiguration::fovy = fovy;
            isDirty = true;
        }
        friend class GTech::Camera;




    };
    class Camera {
        GTech::CameraConfiguration cameraConfiguration;

        glm::vec3 cameraTarget      { glm::vec3(0.0f, 0.0f, -1.0f)};
        glm::vec3 cameraUp          { glm::vec3(0.0f, 1.0f,  0.0f)};
        glm::vec3 cameraPosition    { glm::vec3(0.0f, 0.0f,  1.0f) };
        glm::mat4 vw                { glm::lookAt(cameraPosition, cameraTarget, cameraUp) };
        glm::mat4 pr                { glm::perspective(cameraConfiguration.fovy, cameraConfiguration.aspectRatioW / cameraConfiguration.aspectRatioH, cameraConfiguration.nearClippingPlane, cameraConfiguration.farClippingPlane) };
        glm::mat4 matrix            { pr * vw };
        bool isDirty                { true };

        void Update(){
            matrix = pr * vw;
        }

    public:
        void PrintCam(){
            auto fPrintCam = [](const glm::mat4& m){
                for (auto idxElem = 0; idxElem < 4; idxElem++){
                    for (auto idxCol = 0; idxCol < 4; idxCol++){
                        std::cout << m[idxCol][idxElem] << "\t\t";
                    }
                    std::cout << std::endl;
                }
            };
            fPrintCam(matrix);
            std::cout << "***********" << std::endl;
            fPrintCam(pr);
            std::cout << "***********" << std::endl;
            fPrintCam(vw);
        }
        const glm::mat4& GetCameraMatrix(){
            return matrix;
        }
        const glm::mat4& GetCameraProjectionMatrix(){
            return pr;
        }
        const glm::mat4& GetCameraViewMatrix(){
            return vw;
        }
        CameraConfiguration& GetCameraConfiguration(){
            return cameraConfiguration;
        }
        void UpdateCameraConfiguration(){
            pr = glm::perspective(cameraConfiguration.fovy, cameraConfiguration.aspectRatioW / cameraConfiguration.aspectRatioW, cameraConfiguration.nearClippingPlane, cameraConfiguration.farClippingPlane);
            cameraConfiguration.isDirty = false;
        }
        void UpdateCameraGeometry(){
            vw = glm::lookAt(cameraPosition, cameraTarget, cameraUp);
            isDirty = false;
        }
        void UpdateCamera(){

            auto dirty = false;
            if (isDirty){
                dirty = true;
                UpdateCameraGeometry();
            }
            if (cameraConfiguration.isDirty){
                dirty = true;
                UpdateCameraConfiguration();
            }
            if (dirty) Update();
        }
        void SetCameraPosition(const glm::vec3& rPosition){
            cameraPosition = rPosition;
            isDirty = true;
        }
        void SetCameraTarget(const glm::vec3& rTarget){
            cameraTarget = rTarget;
            isDirty = true;
        }
        void SetCameraUp(const glm::vec3& rUp){
            cameraUp = rUp;
            isDirty = true;
        }

    };
}






using namespace GTech;
int main()
{
    Camera cam;
    cam.PrintCam();
    return 0;
}
