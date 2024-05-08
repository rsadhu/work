const arr = Array.from({ length: 9 }, () => Array.from({ length: 9 }));
//arr =[[]]

function print(...args) {
    process.stdout.write(args.join(' '));
}


function create()
{
    for(let i =1; i <= 9; i++)
    {
        for(let j = 1; j <= 9; j++)
        {
            arr[i-1][j-1] = (i-1) * 9 + j;
        }
    }
}

const display = () =>
{
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            print(arr[i][j], " ");
        }

        print("\n");

    }
}

const display1 = () =>
{
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            print(arr[j][i], " ");
        }

        print("\n");

    }
}

const display2 = () =>
{
    let cnt = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (cnt % 2 == 0)
            {
                print(arr[i][j], " ");
            }
            else{
                print(arr[i][9-1-j], " ");
            }
        }
        cnt++;
        print("\n");
    }
}


const display3 = () =>
{
    let cnt = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (cnt % 2 == 0)
            {
                print(arr[j][i], " ");
            }
            else{
                print(arr[9-1-j][i], " ");
            }
        }
        cnt++;
        print("\n");
    }
}

function diagnol()
{
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (i == j)
            {
                print(arr[i][j], "  ", arr[i][9-1-j]);
            }
        }
        print("\n");
    }
}


function display3x3()
{
    function print3x3(arr, startRow, startCol)
    {
        for ( i = startRow; i < startRow + 3; ++i) {
            for ( j = startCol; j < startCol + 3; ++j) {
                print(arr[i][j], " ");
            }
            print("\n");
        }
    }

    for (i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if (i % 3 == 0 && j % 3 == 0) {
                print3x3(arr, i, j)
            }
        }
    }
}



create();

//print("\n");
//display();

// print("\n");
// display1();

// print("\n");
// display2();

// print("\n");
// display3();


// diagnol();
// print("\n");

display3x3();
print("\n");



