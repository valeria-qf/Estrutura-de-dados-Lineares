"use strict";
document.addEventListener("DOMContentLoaded", function () {
    let mazeArray;
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
    const fileInput = document.getElementById("maze-file");
    fileInput.addEventListener("change", handleFile);
    function handleFile(event) {
        var _a;
        const target = event.target;
        const file = (_a = target.files) === null || _a === void 0 ? void 0 : _a[0]; // se files for null returna undefined
        if (file) {
            readFile(file);
        }
    }
    function readFile(file) {
        const reader = new FileReader();
        reader.onload = function (event) {
            if (event.target) {
                const content = event.target.result;
                processFileContent(content);
            }
        };
        reader.readAsText(file);
    }
    function processFileContent(content) {
        const lines = content.split(/\r\n/).map(line => line.trim());
        const chars = lines.map(line => line.split(''));
        mazeArray = chars;
        drawMaze();
    }
    function setMousePosition(x, y) {
        mouse.style.top = x + "px";
        mouse.style.left = y + "px";
    }
    function setCheesePosition(x, y) {
        cheese.style.bottom = x + "px";
        cheese.style.right = y + "px";
    }
    ;
    function drawMaze() {
        maze.innerHTML = "";
        for (let rows = 0; rows < mazeArray.length; rows++) {
            const row = document.createElement("div");
            row.classList.add("row");
            for (let columns = 0; columns < mazeArray[rows].length; columns++) {
                const cell = document.createElement("div");
                cell.classList.add("cell");
                if (mazeArray[rows][columns] == '1') {
                    cell.classList.add("wall");
                }
                if (mazeArray[rows][columns] == 'm') {
                    cell.appendChild(mouse);
                }
                else if (mazeArray[rows][columns] == 'e') {
                    cell.appendChild(cheese);
                }
                row.appendChild(cell);
            }
            maze.appendChild(row);
        }
        maze.style.display = "block";
    }
});
