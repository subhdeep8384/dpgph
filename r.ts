const stack : number[] = []

stack.push(1) 
stack.push(5) 
stack.push(4) 
stack.push(3) 
stack.push(2) 

while(stack.length > 0 ){
    let el = stack.pop() ;
    console.log(el)
}