void move(*Character Character, *Map Map, int direction)
{
    intarray<int, 2> coordinates = Character.getCoordinates();
    int pos = (coordinates[1]-1) * Map.lineSize() + coordinates[0];
    
    if(direction == 0)
    {
        int pos = pos + Map.lineSize;
    }
    if(direction == 1)
    {
        int pos = pos - Map.lineSize;
    }
    if(direction == 2)
    {
        int pos = pos - 1;
    }
    if(direction == 3)
    {
        int pos = pos - 1;
    }

    if(Map.isAccessible(pos) && pos > -1 && pos < Map.lineSize*Map.colSize)
        {
            coordinates[0] = pos % Map.lineSize;
            coordinates[1] = pos / Map.lineSize;

            Item* item = Map.foundSomething(pos)
            if(item != nullptr)
            {
                Item* replace = Character.replaceInventory(item);
                if(item != nullptr)
                {
                    delete replace;
                }
            }
        }

    
}