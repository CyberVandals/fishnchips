#include "inc/koffi/kk_levelbuilder.h"
#include "inc/koffi/kk_levelitem.h"
#include "inc/gy_objecthandler.h"

LevelBuilder::LevelBuilder() {}

LevelBuilder::LevelBuilder(ObjectHandler *object_handler)
{
    this->object_handler = object_handler;
}


void LevelBuilder::position(LevelItem levelItem)
{
    position_shark(levelItem);
    position_banana(levelItem);
    position_exit(levelItem);
    position_platform(levelItem);
    position_steam(levelItem);
    qDebug() << "positioning items\n";
}

void LevelBuilder::position_player(LevelItem levelItem)
{
    // TODO changed in scene manager
}

void LevelBuilder::position_shark(LevelItem levelItem)
{
    if(levelItem.title().compare("SHARK") == 0) {
        object_handler->add_shark(levelItem.x(), levelItem.y());
    }
    qDebug() << "shark object: " << object_handler;
}

void LevelBuilder::position_banana(LevelItem levelItem)
{
    if(levelItem.title().compare("BANANA") == 0) {
        object_handler->add_banana(levelItem.x(), levelItem.y());
    }
}

void LevelBuilder::position_exit(LevelItem levelItem)
{
    if(levelItem.title().compare("EXIT") == 0) {
        object_handler->add_exit(levelItem.x(), levelItem.y());
    }
}

void LevelBuilder::position_platform(LevelItem levelItem)
{
    if(levelItem.title().compare("PLATFORM") == 0) {
        object_handler->add_platform(levelItem.x(), levelItem.y());
    }
}

void LevelBuilder::position_steam(LevelItem levelItem)
{
    if(levelItem.title().compare("STEAM") == 0) {
        object_handler->add_steam(levelItem.x(), levelItem.y());
    }

    qDebug() << "object in position steam: " << object_handler << levelItem.x();
}
