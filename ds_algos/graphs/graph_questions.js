const largest_graph = (grp, st, lookup) =>
{
    if (lookup.has(st)) return 0;
    lookup.add(st);
    size = 1;

    for (let ngh of grp[st])
    {
        size += largest_graph(grp, ngh, lookup);
    }
    return size;
}


const grp =  {
    '0': ['8','1','5'],
    '1': ['0'],
    '5':['0','8'],
    '8':['0','5'],
    '2':['3','4'],
    '3':['2','4'],
    '4':['3','2']
};


max_size = 0;
for (let ngh in grp)
{
    max_size = Math.max( max_size, largest_graph(grp, ngh, new Set()));
}


console.log(max_size);

