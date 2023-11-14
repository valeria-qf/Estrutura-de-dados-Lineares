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
    let mouse= document.getElementById("mouse") as HTMLImageElement;
    let cheese = document.getElementById("cheese") as HTMLImageElement;;
    let maze = document.getElementById("maze-container") as HTMLDivElement;


    function setMousePosition(x: number, y: number) {
            mouse.style.top = x + "px"
            mouse.style.left = y + "px"
    }

    function setCheesePosition(x: number, y: number) {
        cheese.style.bottom = x + "px"
        cheese.style.right = y + "px"
    }


    levelSelect.addEventListener("change", function () {
        let level: string = levelSelect.value
        if (level == "1") {
            mazeArray = level1;
        }

        else if (level == "2") {
            mazeArray = level2;
        }

        let mouseImage: string = `<img id="mouse" src="img/mouse.png" alt="ilustration of a mouse">`;
        let cheeseImage: string = `<img id="cheese" src="/img/cheese.png" alt="ilustration of a cheese slice">`;
        maze.innerHTML = mouseImage + cheeseImage
        drawMaze()

    })


    function drawMaze(): void {



        for (let i = 0; i < mazeArray.length; i++) {
            let row: HTMLDivElement = document.createElement("div");
            row.classList.add("row");

            for (let j = 0; j < mazeArray[i].length; j++) {
                let cell: HTMLDivElement = document.createElement("div");
                cell.classList.add("cell");

                if (mazeArray[i][j] == 0) {
                    cell.classList.add("wall");
                }
                row.appendChild(cell);
            }
            maze.appendChild(row);
        }
        setMousePosition(0, 0)
    }
    drawMaze()
});
