#ifndef FIRST_SCENE_H
#define FIRST_SCENE_H
#include <ThreeDemoModel.h>
#include <three/helpers/AxesHelper.h>
class FirstScene : public ThreeDemoClass {
public:
	FirstScene(int x, int y) :  ThreeDemoClass(x,y) {

	}
	virtual void init() override {

        renderer->shadowMap->enabled = true;
        renderer->shadowMap->type = ShadowMapType::PCFSoftShadowMap;

		camera = std::make_shared<PerspectiveCamera>(45.0f, screenX/screenY , 0.1f, 1000.0f);
		camera->position.set(-30.0f, 50.0f, 40.0f);
		camera->lookAt(Vector3());

        isPerspective = true;

        Vector4 screen = Vector4(0, 0, screenX, screenY);
        controller = std::make_shared<TrackballControls>(camera, screen);

        controller->staticMoving = true;
        controller->rotateSpeed = 3.0f;
        controller->zoomSpeed = 2;
        controller->panSpeed = 2;
        controller->noZoom = false;
        controller->noPan = false;
        controller->noRotate = false;
        controller->dynamicDampingFactor = 0.2f;

        scene = std::make_shared<Scene>();
        scene->setBackgroundColor(Color().set(0xffffff));


        auto axis = std::make_shared<AxesHelper>(20);
        auto planeGeometry = std::make_shared<PlaneGeometry>(60, 20);
        auto planeMaterial = std::make_shared<MeshBasicMaterial>();
        planeMaterial->color = Color(0xcccccc);
        auto plane = std::make_shared<Mesh>(planeGeometry, planeMaterial);

        plane->rotation.setX((float)(-0.5f * M_PI));

        plane->position.set(15.0f, 0.0f, 0.0f);

        auto cubeGeometry = std::make_shared<BoxGeometry>(4, 4, 4);
        auto cubeMaterial = std::make_shared<MeshBasicMaterial>();
        cubeMaterial->color = Color(0xff0000);
        cubeMaterial->wireframe = true;
        auto cube = std::make_shared<Mesh>(cubeGeometry, cubeMaterial);
        cube->position.set(-4.0f, 3.0f, 0.0f);
        scene->add(axis);
        scene->add(plane);
        scene->add(cube);

        auto sphereGeometry = std::make_shared<SphereGeometry>(4, 20, 20);
        auto sphereMaterial = std::make_shared<MeshBasicMaterial>();
        auto sphere = std::make_shared<Mesh>(sphereGeometry, sphereMaterial);
        sphereMaterial->color = Color(0x7777ff);
        sphereMaterial->wireframe = true;

        sphere->position.set(20, 4, 2);
        scene->add(sphere);

        //this->initialized = true;
	}
};
#endif