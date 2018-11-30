#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat2x3.hpp>

#include <memory>
#include <functional>


class _CoordManager {
public:
    enum class Origin {TOP_LEFT, BOTTOM_LEFT, CENTER, CENTER_DOWNWARDS};

private:

    Origin          origin{Origin::BOTTOM_LEFT};
    glm::ivec3      screenSize;
    glm::ivec3      worldCoordinatesOrigin;


    glm::mat2x3     screenCoordinates{glm::mat2x3(glm::ivec3(1, 0, 0), glm::ivec3(0, -1, screenSize.y - 1))};

    _CoordManager() = default;

public:

    static _CoordManager*   pCoordManager;
    static _CoordManager*   GetCoordManager();



    void            DestroyCoordManager();

    void            SetOrigin(_CoordManager::Origin origin);
    void            SetViewPortSize(const glm::ivec2 &viewPortSize);


    glm::ivec3      ToScreenCoordinate(const glm::ivec3& coordinate);

};

int main()
{
    auto pCoordManager = _CoordManager::GetCoordManager();
    auto localPos = glm::ivec3(1,2,3);
    auto anchor2world = glm::mat3x3(1,1,1,2,2,2,3,3,3);
    auto worldPos = localPos * anchor2world ;
    return 0;
	
}




_CoordManager* _CoordManager::pCoordManager = nullptr;


_CoordManager* _CoordManager::GetCoordManager() {

    pCoordManager = (pCoordManager == nullptr) ? new _CoordManager() : pCoordManager;
    return pCoordManager;

}

void _CoordManager::DestroyCoordManager() {

    if (pCoordManager) {
        delete pCoordManager;
        pCoordManager = nullptr;
    }

}

void _CoordManager::SetOrigin(_CoordManager::Origin origin) {

    this->origin = origin;
    if (origin == Origin::BOTTOM_LEFT){
        screenCoordinates = glm::mat2x3(glm::ivec3(1, 0, 0), glm::ivec3(0, -1, screenSize.y - 1));
    }
}

void _CoordManager::SetViewPortSize(const glm::ivec2 &viewPortSize) {

    screenSize = glm::ivec3(viewPortSize.x,viewPortSize.y, 0);

}

inline glm::ivec3 _CoordManager::ToScreenCoordinate(const glm::ivec3& coordinate) {

    auto result = coordinate * screenCoordinates;
    return glm::ivec3(1,1,1);

}


