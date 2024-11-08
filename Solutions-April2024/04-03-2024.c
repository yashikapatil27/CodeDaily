bool dfs(char** board, int row, int col, int boardSize, int* boardColSize, char* word, int index, bool** visited)
{
    if(index == strlen(word))
    {
        return true;
    }

    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize[row])
    {
        return false;
    }
        
    if (visited[row][col] || board[row][col] != word[index])
    {
        return false;
    }

    visited[row][col] = true;

    bool move = dfs(board, row+1, col, boardSize, boardColSize, word, index+1, visited) ||
                dfs(board, row, col+1, boardSize, boardColSize, word, index+1, visited) ||
                dfs(board, row-1, col, boardSize, boardColSize, word, index+1, visited) ||
                dfs(board, row, col-1, boardSize, boardColSize, word, index+1, visited);

    visited[row][col] = false;

    return move;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    if(board==NULL || boardSize==0 || boardColSize==0 || word==NULL)
    {
        return false;
    }

    bool** visited = (bool**)malloc(boardSize*sizeof(bool*));

    for(int i=0; i<boardSize; i++)
    {
        visited[i] = (bool*)calloc(boardColSize[i], sizeof(bool));
    }

    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardColSize[i]; j++)
        {
            if(dfs(board, i, j, boardSize, boardColSize, word, 0, visited))
            {
                for(int k=0; k<boardSize; k++)
                {
                    free(visited[k]);
                }
                free(visited);
                return true;
            }
        }
    }

    for (int i = 0; i < boardSize; i++) {
        free(visited[i]);
    }
    free(visited);

    return false;
}