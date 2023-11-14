"use strict";
document.addEventListener("DOMContentLoaded", function () {
    const level1 = [
        [1, 0, 1, 0],
        [1, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 0, 1, 1],
    ];
    const level2 = [
        [1, 0, 1, 0, 1],
        [1, 1, 1, 1, 1],
        [1, 0, 0, 1, 0],
        [1, 1, 0, 1, 1],
    ];
    let mazeArray = level1;
    const levelSelect = document.getElementById("level-select");
    let maze = document.getElementById("maze-container");
    let mouse;
    let cheese;
    mouse = createImage("mouse", "img/mouse.png", "ilustration of a mouse");
    cheese = createImage("cheese", "img/cheese.png", "ilustration of a cheese slice");
    function createImage(id, src, alt) {
        const image = document.createElement("img");
        image.id = id;
        image.src = src;
        image.alt = alt;
        return image;
    }
    function setMousePosition(x, y) {
        mouse.style.top = x + "px";
        mouse.style.left = y + "px";
    }
    function setCheesePosition(x, y) {
        cheese.style.bottom = x + "px";
        cheese.style.right = y + "px";
    }
    levelSelect.addEventListener("change", function () {
        const level = levelSelect.value;
        if (level == "1") {
            mazeArray = level1;
        }
        else if (level == "2") {
            mazeArray = level2;
        }
        drawMaze();
    });
    function drawMaze() {
        maze.innerHTML = "";
        maze.appendChild(mouse);
        maze.appendChild(cheese);
        for (let rows = 0; rows < mazeArray.length; rows++) {
            const row = document.createElement("div");
            row.classList.add("row");
            for (let columns = 0; columns < mazeArray[rows].length; columns++) {
                const cell = document.createElement("div");
                cell.classList.add("cell");
                if (mazeArray[rows][columns] == 0) {
                    cell.classList.add("wall");
                }
                row.appendChild(cell);
            }
            maze.appendChild(row);
        }
    }
    drawMaze();
});
