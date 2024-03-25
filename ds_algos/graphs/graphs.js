class graph{

    constructor()
    {

    }

    dfs(graph, source)
    {
        let lookup = new Set();
        let stack = [source];
        lookup.add(source);
        while(stack.length > 0)
        {
            const cur = stack.pop();
            console.log(cur);
            for (let child of graph[cur])
            {
                if (!lookup.has(child))
                {
                    lookup.add(cur);
                    stack.push(child)
                }
            }
        }

    }

    dfs_rec(graph, source, lookup)
    {
        if (lookup.has(source))
        {
            return;
        }

        lookup.add(source);
        console.log(source);
        for (let child of graph[source])
        {
            this.dfs_rec(graph, child, lookup);
        }
    }

    bfs(graph, source)
    {
        let queue =  [source];
        while(queue.length > 0)
        {
            const cur = queue.shift();
            console.log(cur);
            for(let child of graph[cur])
            {
                queue.push(child);
            }
        }
    }

    hasPath(graph, source, dest, lookup=new Set())
    {
        if (source === dest)
            return true;

        lookup.add(source);
        for (let child of graph[source])
        {
            if (!lookup.has(child))
                if (this.hasPath(graph, child, dest, lookup) === true)
                {
                    return true;
                }
        }

        return false;
    }

};



const grp =  {
    a: ['b', 'c'],
    b: ['d'],
    c: ['e'],
    d: ['f'],
    e: [],
    f: []
};


g = new graph();


const countIsland = (islands, row, col) =>
{
    if ( (row < 0 || col > islands[0].length ) || islands[row][col] != "1" || row > islands.length )
        return false;

    islands[row][col] = "2";

    countIsland(islands, row+1, col);
    countIsland(islands, row-1, col);
    countIsland(islands, row, col-1);
    countIsland(islands, row, col+1);
    return true;
}

const islands = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
];

counter =  0;
for (i = 0; i < islands.length; i++)
{
    for(j = 0; j < islands[i].length; j++)
    {
        if (countIsland(islands, i, j))
        {
            counter++;
        }
    }
}

console.log(counter);




