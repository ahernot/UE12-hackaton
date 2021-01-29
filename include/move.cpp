void move(Character* character, Map* map, int direction)
{
    std::array<int, 2> coordinates = character->getCoordinates();
    int pos = (coordinates[1]-1) * map->lineSize + coordinates[0];
    
    if(direction == 0)
    {
        pos = pos + map->lineSize;
    }
    if(direction == 1)
    {
        pos = pos - map->lineSize;
    }
    if(direction == 2)
    {
        pos = pos - 1;
    }
    if(direction == 3)
    {
        pos = pos + 1;
    }

    /* if(map->isAccessible(pos) && pos > -1 && pos < map->lineSize*map->colSize)
        { */
            coordinates[0] = pos % map->lineSize;
            coordinates[1] = pos / map->lineSize;

            /* Item* item = map->foundSomething(pos);
            if(item != nullptr)
            {
                Item* replace = character->replaceInventory(item);
                if(item != nullptr)
                {
                    delete replace;
                }
            } */
       

    character->updatePosition(coordinates[0], coordinates[1]);
}