typedef struct{
    int score;
    int index;
}Athlete;

int compare(const void* a, const void* b)
{
    const Athlete* athleteA = (const Athlete*)a;
    const Athlete* athleteB = (const Athlete*)b;

    return (athleteB->score - athleteA->score);
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) 
{
    char** res = (char**)malloc(scoreSize*sizeof(char*));
    Athlete* athletes = (Athlete*)malloc(scoreSize*sizeof(Athlete));

    for(int i=0; i<scoreSize; i++)
    {
        athletes[i].score = score[i];
        athletes[i].index = i;
    }

    qsort(athletes, scoreSize, sizeof(Athlete), compare);

    for(int i=0; i<scoreSize; i++)
    {
        if(i==0)
        {
            res[athletes[i].index] = strdup("Gold Medal");
        }
        else if(i==1)
        {
            res[athletes[i].index] = strdup("Silver Medal");
        }
        else if (i == 2)
        {
            res[athletes[i].index] = strdup("Bronze Medal");
        }
        else 
        {
            char* rankString = (char*)malloc(16 * sizeof(char));
            sprintf(rankString, "%d", i + 1);
            res[athletes[i].index] = rankString;
        }
    }
    free(athletes);
    
    *returnSize = scoreSize;
    return res;
}