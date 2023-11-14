"use strict";
document.addEventListener("DOMContentLoaded", function () {
    let level1 = [
        [1, 0, 1, 0],
        [1, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 0, 1, 1],
    ];
    let level2 = [
        [1, 0, 1, 0, 1],
        [1, 1, 1, 1, 1],
        [1, 0, 0, 1, 0],
        [1, 1, 0, 1, 1],
    ];
    let mazeArray = level1;
    let levelSelect = document.getElementById("level-select");
    let mouse = document.getElementById("mouse");
    let cheese = document.getElementById("cheese");
    ;
    let maze = document.getElementById("maze-container");
    function setMousePosition(x, y) {
        mouse.style.top = x + "px";
        mouse.style.left = y + "px";
    }
    function setCheesePosition(x, y) {
        cheese.style.bottom = x + "px";
        cheese.style.right = y + "px";
    }
    levelSelect.addEventListener("change", function () {
        let level = levelSelect.value;
        if (level == "1") {
            mazeArray = level1;
        }
        else if (level == "2") {
            mazeArray = level2;
        }
        let mouseImage = `<img id="mouse" src="img/mouse.png" alt="ilustration of a mouse">`;
        let cheeseImage = `<img id="cheese" src="/img/cheese.png" alt="ilustration of a cheese slice">`;
        maze.innerHTML = mouseImage + cheeseImage;
        drawMaze();
    });
    function drawMaze() {
        for (let i = 0; i < mazeArray.length; i++) {
            let row = document.createElement("div");
            row.classList.add("row");
            for (let j = 0; j < mazeArray[i].length; j++) {
                let cell = document.createElement("div");
                cell.classList.add("cell");
                if (mazeArray[i][j] == 0) {
                    cell.classList.add("wall");
                }
                row.appendChild(cell);
            }
            maze.appendChild(row);
        }
        setMousePosition(0, 0);
    }
    drawMaze();
});
