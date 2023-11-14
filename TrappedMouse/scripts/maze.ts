document.addEventListener("DOMContentLoaded", function () {

    let mazeArray: string[][]
    let maze = document.getElementById("maze-container") as HTMLDivElement;
    let mouse: HTMLImageElement;
    let cheese: HTMLImageElement;

    mouse = createImage("mouse", "img/mouse.png", "ilustration of a mouse");
    cheese = createImage("cheese", "img/cheese.png", "ilustration of a cheese slice");

    function createImage(id: string, src: string, alt: string): HTMLImageElement {
        const image = document.createElement("img");
        image.id = id;
        image.src = src;
        image.alt = alt;
        return image;
    }

    const fileInput = document.getElementById("maze-file") as HTMLInputElement

    fileInput.addEventListener("change", handleFile)

    function handleFile(event: Event): void {
        const target = event.target as HTMLInputElement
        const file = target.files?.[0] // se files for null returna undefined

        if (file) {
            readFile(file)
        }
    }

    function readFile(file: File) {

        const reader = new FileReader();

        reader.onload = function (event) {
            if (event.target) {
                const content = event.target.result as string
                processFileContent(content)
            }
        }
        reader.readAsText(file);
    }

    function processFileContent(content: string) {

        const lines = content.split(/\r\n/).map(line => line.trim())
        const chars = lines.map(line => line.split(''))
        mazeArray = chars

        drawMaze()
    }

    function setMousePosition(x: number, y: number) {
        mouse.style.top = x + "px";
        mouse.style.left = y + "px";
    }

    function setCheesePosition(x: number, y: number) {
        cheese.style.bottom = x + "px";
        cheese.style.right = y + "px";
    };

    function drawMaze(): void {

        maze.innerHTML = "";
        
        for (let rows = 0; rows < mazeArray.length; rows++) {
            const row: HTMLDivElement = document.createElement("div");
            row.classList.add("row");
            
            for (let columns = 0; columns < mazeArray[rows].length; columns++) {
                const cell: HTMLDivElement = document.createElement("div");
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
