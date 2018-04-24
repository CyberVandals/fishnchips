#ifndef MM_RESOURCEMANAGER_H
#define MM_RESOURCEMANAGER_H


class ResourceManager{

public:

    ResourceManager();

    //This method uses dynamic binding to implement volume control for the SoundManager class
    virtual void adjust_volume();
};

#endif // MM_RESOURCEMANAGER_H
