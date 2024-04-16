const startTime = new Date();

i=0;
while(i < 1000000000)
{
    i+=1;
}

const endTime = new Date();
const timeDifference = endTime - startTime; // Difference in milliseconds
console.log('Time difference:', timeDifference, 'milliseconds');
