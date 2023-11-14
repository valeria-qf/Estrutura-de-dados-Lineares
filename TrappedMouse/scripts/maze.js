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
    let mouse = `<img id="mouse" src="img/mouse.png" alt="ilustration of a mouse">`;
    let cheese = `<img id="cheese" src="/img/cheese.png" alt="ilustration of a cheese slice">`;
    let maze = document.getElementById("maze-container");
    ;
    let mazearray = level1;
    let levelselect = document.getElementById("levelselect");
    if (levelselect) {
        levelselect.addEventListener("change", function () {
            let level = levelselect.value;
            if (level == "1") {
                mazearray = level1;
            }
            else if (level == "2") {
                mazearray = level2;
            }
            drawMaze();
        });
    }
    function drawMaze() {
        if (maze) {
            maze.innerHTML = mouse + cheese;
            for (let i = 0; i < mazearray.length; i++) {
                let row = document.createElement("div");
                row.classList.add("row");
                for (let j = 0; j < mazearray[i].length; j++) {
                    let cell = document.createElement("div");
                    cell.classList.add("cell");
                    if (mazearray[i][j] == 0) {
                        cell.classList.add("wall");
                    }
                    row.appendChild(cell);
                }
                maze.appendChild(row);
            }
        }
    }
    drawMaze();
});
