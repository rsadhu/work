const countIsland = (islands, row, col) =>
{
    if ( (row < 0 || col > islands[0].length -1 ) || (row > islands.length -1) || islands[row][col] != "1" )
        return 0;

    islands[row][col] = "2";

    return 1 + countIsland(islands, row+1, col) + countIsland(islands, row-1, col)
            + countIsland(islands, row, col-1) + countIsland(islands, row, col+1);
}



const islands2 = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ];


    let counter =  0;
    for (i = 0; i < islands2.length; i++)
    {
        for(j = 0; j < islands2[i].length; j++)
        {
            let tmp =  countIsland(islands2, i, j);
            if (tmp!=0) {
                console.log(tmp);
                counter = Math.max(tmp, counter);
            }
        }
    }


console.log(counter);




