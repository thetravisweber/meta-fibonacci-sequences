// short for graphing window
let gWindow = {
  x: 10,
  y: 10
}

let masterSequence = [1, 1];

function setup() {
  createCanvas(400, 400);
}

function draw() {
  background(220);
  stroke(0);
  drawTicks();
  fill(209,198,228);
  for (let i = 2; i < masterSequence.length; i++)
  {
    let node = masterSequence[i];
    let x = node.firstChild();
    let y = node.secondChild();
    let p = convertToWindow(x, y);
    ellipse(p.x, p.y, 5, 5);
  }
}

function convertToWindow(x, y)
{
  return createVector(
    x * sizes().x,
    y * sizes().y
  );
} 

function addTerm()
{

}

function sizes()
{
  return {
    x: width / gWindow.x + 1,
    y: height / gWindow.y + 1
  }
}

function drawTicks()
{
  let xSize = sizes().x;
  let ySize = sizes().y;
  for (let x = 0; x <= gWindow.x; x++)
  {
    line(x * xSize, 0, x*xSize, height);
  }

  for (let y = 0; y <= gWindow.y; y++)
  {
    line(0, y * ySize, width, y*ySize);
  }
}