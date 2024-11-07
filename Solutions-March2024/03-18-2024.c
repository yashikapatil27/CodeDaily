int compare(const void* a, const void* b) {
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    
    if (interval1[1] < interval2[1]) 
    {
        return -1;
    }
    else if (interval1[1] > interval2[1]) 
    {
        return 1;
    }
    else 
    {
        if (interval1[0] < interval2[0]) 
        {
            return -1;
        }
        else if (interval1[0] > interval2[0]) 
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
    }
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 1) {
        return pointsSize;
    }

    int arrows = 1;

    qsort(points, pointsSize, sizeof(int*), compare);

    int point = points[0][1];

    for(int i=1; i<pointsSize; i++)
    {
        if(points[i][0] > point)
        {
            arrows++;
            point = points[i][1];
        }
    }
    return arrows;
}
