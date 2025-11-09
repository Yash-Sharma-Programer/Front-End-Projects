// Select DOM elements
const input = document.getElementById('todo-input')
const addBtn = document.getElementById('add-btn')
const list = document.getElementById("todo-list")

// Try to load svaed todos array from localStorage (If any)
const saved = localStorage.getItem('todos');
const todos = saved ? JSON.parse(saved) : [];

function saveTodos() {
    // Save Current todos array to localStorage
    localStorage.setItem('todos', JSON.stringify(todos));
}

// Create a DOM node for a todo object and append it to the list
function createTodoNode(todo, index) {
    const li = document.createElement('li')

    // checbox to toogle completion
    const checkbox = document.createElement('input')
    checkbox.type = 'checkbox';
    checkbox.checked = !!todo.completed;
    checkbox.addEventListener("change", () => {
        todo.completed = checkbox.checked;

        // Todo :  visual feedback: Strike through when completed
        textSpan.style.textDecoration = todo.completed ? 'line-through' : '';
        saveTodos();
    })

    // Text of the todo
    const textSpan = document.createElement("span")
    textSpan.textContent = todo.text;
    textSpan.style.margin = '0 8px'
    if (todo.completed) {
        textSpan.style.textDecoration = 'line-through';
    }
    // Add double click event listner to edit todo
    textSpan.addEventListener("dblclick", () => {
        const newText = prompt("Edit todo", todo.text)
        if (newText !== null) {
            todo.text = newText.trim()
            textSpan.textContent = todo.text;
            saveTodos();
        }
    })

    // Delete Todo Button
    const delBtn = document.createElement('button')
    delBtn.textContent = 'Delete';
    delBtn.addEventListener('click', () => {
        todos.splice(index, 1);
        render();
        saveTodos();
    })

    li.appendChild(checkbox);
    li.appendChild(textSpan);
    li.appendChild(delBtn);
    return li;
}


// REnder the whole todo list from the array
function render() {
    list.innerHTML = '';

    //Recrate Each item
    todos.forEach((todo, index) => {
        const node = createTodoNode(todo, index)
        console.log(node, todo)
        list.appendChild(node)
    });
}

function addTodo() {
    const text = input.value.trim();
    if (!text) {
        return
    }

    // Push a new Todo object
    todos.push({ text, completed: false });
    input.Value = '';
    render();
    saveTodos();
}

addBtn.addEventListener("click", addTodo);
input.addEventListener('keydown', (e) => {
    if (e.key == 'Enter') {
        addTodo();
    }
})
render();
