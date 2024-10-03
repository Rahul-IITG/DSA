using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
    int grid[width][height];
    grid[0][0]=1;

    for (int i=0;i<width;i++) {
        grid[i][0]=1;
    }
    for (int i=0;i<height;i++) {
        grid[0][i]=1;
    }

    for (int i=1;i<width;i++) {
        for (int j=1;j<height;j++) {
            grid[i][j]=grid[i-1][j] + grid[i][j-1];
        }
    }

    return grid[width-1][height-1];
}