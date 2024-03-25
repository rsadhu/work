class Node{
    constructor(d)
    {
        this.data = d;
        this.next = null;
    }
};

var head = null;

function append(data)
{
    if (!head)
    {
        head = new Node(data);
    }
    else
    {
        let tra = head;
        while(tra != null)
        {
            tra.next = new Node(data);
            tra = tra.next;
        }
    }
}


function prepend(data)
{

}

function display()
{
    let tra = head;
    while(tra)
    {
        console.log(tra.data, "  ");
        tra = tra.next;
    }
}

for (i=1;i<=10;i++)
    append(i);

display();




