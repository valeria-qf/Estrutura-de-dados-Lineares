document.addEventListener("DOMContentLoaded", function () {
    let level1: number[][] = [
        [1, 0, 1, 0],
        [1, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 0, 1, 1],
    ];

    let level2: number[][] = [
        [1, 0, 1, 0, 1],
        [1, 1, 1, 1, 1],
        [1, 0, 0, 1, 0],
        [1, 1, 0, 1, 1],
    ];

    let mazeArray: number[][] = level1;
    let levelSelect = document.getElementById("level-select") as HTMLSelectElement;
    let maze = document.getElementById("maze-container") as HTMLDivElement;
    let mouse: HTMLImageElement;
    let cheese: HTMLImageElement;

    // Adicionar o mouse e o queijo uma única vez
    mouse = createImage("mouse", "img/mouse.png", "ilustration of a mouse");
    cheese = createImage("cheese", "img/cheese.png", "ilustration of a cheese slice");

    function createImage(id: string, src: string, alt: string): HTMLImageElement {
        let image = document.createElement("img");
        image.id = id;
        image.src = src;
        image.alt = alt;
        return image;
    }

    function setMousePosition(x: number, y: number) {
        mouse.style.top = x + "px";
        mouse.style.left = y + "px";
    }

    function setCheesePosition(x: number, y: number) {
        cheese.style.bottom = x + "px";
        cheese.style.right = y + "px";
    }

    levelSelect.addEventListener("change", function () {
        let level: string = levelSelect.value;
        if (level == "1") {
            mazeArray = level1;
        } else if (level == "2") {
            mazeArray = level2;
        }

        drawMaze();
    });


    function drawMaze(): void {
        
        maze.innerHTML = "";
        maze.appendChild(mouse);
        maze.appendChild(cheese);

        for (let rows = 0; rows < mazeArray.length; rows++) {
            let row: HTMLDivElement = document.createElement("div");
            row.classList.add("row");

            for (let columns = 0; columns < mazeArray[rows].length; columns++) {
                let cell: HTMLDivElement = document.createElement("div");
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
