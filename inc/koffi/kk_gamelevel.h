#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#endif // GAMELEVEL_H

class GameLevel
{
public:
    GameLevel();
    void loadHighestScore();
    void updateHighesrScore();
private:
    int levelNumber;
    int highestScore;
};
