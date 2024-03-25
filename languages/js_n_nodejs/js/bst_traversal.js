class Node{
    constructor(val)
    {
        this.val = val;
        this.left = null
        this.right = null
    }

    display()
    {
        console.log("value is ", String(this.val) );
    }
}

function inOrder(root)
{
    if (root == null)
        return
    inOrder(root.left)
    console.log(String(root.val))
    inOrder(root.right)
}

const depthfirstsearch = (root) =>
{
    const stack = [root];
    while(stack.length > 0)
    {
        const current = stack.pop();
        console.log(String(current.val));
        if (current.right) stack.push(current.right);
        if (current.left) stack.push(current.left);
    }
}


a = new Node(1);
b = new Node(2);
c = new Node(3);
d = new Node(4);
e = new Node(5);
f = new Node(6);
g = new Node(7);

d.left = b;
d.right = f;
b.left = a;
b.right = c;
f.left = e;
f.right = g;


inOrder(d);
d.display();

depthfirstsearch(d);


let x = 10;
y = 20;
console.log(x, y);
function test() {
   let x = 50;
   var y = 100;
   console.log(x, y);
}
test();
console.log(x, y);


