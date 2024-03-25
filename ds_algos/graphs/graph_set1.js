const hasPath= (graph, source, dest, lookup=new Set()) =>
{
    if (source === dest)
        return true;

    lookup.add(source);
    for (let child of graph[source])
    {
        if (!lookup.has(child))
            if (hasPath(graph, child, dest, lookup) === true)
            {
                return true;
            }
    }

    return false;
}


function hasPathBst(graph, source, dest, lookup=new Set())
{
    const queue = [source];
    lookup.add(source);
    while(queue.length > 0)
    {
        const cur = queue.shift();
        if(cur === dest)
            return true;

        for(let child of graph[cur])
        {
            if (!lookup.has(child))
            {
                lookup.add(child)
                queue.push(child);
            }
        }
    }
    return false;
}



const grp1 =  {
    f: ['g', 'i'],
    g: ['h'],
    h: [],
    i: ['g', 'k'],
    j: ['i'],
    k: []
};

// console.log(hasPath(grp1, 'j', 'f')); //false
// console.log(hasPath(grp1, 'j', 'k')); //true
// console.log(hasPath(grp1, 'f', 'h')); //true
// console.log(hasPath(grp1, 'i', 'h')); // true



// console.log(hasPathBst(grp1, 'j', 'f')); //false
// console.log(hasPathBst(grp1, 'j', 'k')); //true
// console.log(hasPathBst(grp1, 'f', 'h')); //true
// console.log(hasPathBst(grp1, 'i', 'h')); // true




const edges =
[
    ['i', 'j'],
    ['k','i'],
    ['m','k'],
    ['k','l'],
    ['o','n']
];

const build_adj=(egdes)=>
{
    const gph = {};
    for (const [a, b] of edges)
    {
     //   console.log(a, b);
        if (!(a in gph))
            gph[a]=[];

        if (!(b in gph))
            gph[b]=[];

        gph[a].push(b);
        gph[b].push(a);

    }
    return gph;
}



const adj =  build_adj(edges);
console.log(adj);

console.log(hasPath(adj, 'j', 'm')); //false
console.log(hasPath(adj, 'j', 'k')); //true
console.log(hasPath(adj, 'o', 'j')); //true
console.log(hasPath(adj, 'k', 'i')); // true



console.log(hasPathBst(adj, 'j', 'm')); //false
console.log(hasPathBst(adj, 'j', 'k')); //true
console.log(hasPathBst(adj, 'o', 'j')); //true
console.log(hasPathBst(adj, 'k', 'i')); // true

//console.log(adj);

