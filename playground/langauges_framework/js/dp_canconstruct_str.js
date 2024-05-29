function canConstructor( word, list, memo={})
{
	if (word in memo)	return true;

	if (word.length  === 0)
		return true;

	for (let str of list)
	{
		if (word.startsWith(str) === true) 
		{
			let  suffix = word.slice(str.length);

			if (canConstructor(suffix, list, memo))
			{
				memo[word] = true;
				return true;
			}
		}
	}
	memo[word] = true;
	return false;
}



console.log(
	canConstructor("abcdef", ["ab", "abc", "cd", "def","abcd"])
);


console.log(
	canConstructor("abef", ["ab", "abc", "cd", "def","abcd"])
);


console.log(
	canConstructor("eeeeeeeeeeeeeeeeeeeeeeee", ["e", "ee", "eee", "eeee","eeee", "eeeee"])
);