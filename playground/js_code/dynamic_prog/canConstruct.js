function canConstruct(target, list, memo={})
{
    if (target in memo) return memo[target];

    if (target === '') return true;


    for(let str of list)
    {
        if (target.indexOf(str) === 0)
        {
            if (canConstruct(target.slice(str.length), list, memo))
            {
                memo[target] = true;
                return true;
            }
        }
    }

    memo[target] = false;
    return false;

}



console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]))

console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeeeeeeeeeeeee"]))

