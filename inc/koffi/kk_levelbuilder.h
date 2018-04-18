#ifndef KK_LEVELBUILDER_H
#define KK_LEVELBUILDER_H

#endif // KK_LEVELBUILDER_H

#include <QString>


class ObjectHandler;

class LevelItem;

class LevelBuilder
{
public:
    LevelBuilder();
    LevelBuilder(ObjectHandler *object_handler);

    void position(LevelItem levelItem);

private:
    ObjectHandler *object_handler;

    void position_shark(LevelItem levelItem);
    void position_player(LevelItem levelItem);
    void position_banana(LevelItem levelItem);
    void position_exit(LevelItem levelItem);
    void position_platform(LevelItem levelItem);
    void position_steam(LevelItem levelItem);
};
