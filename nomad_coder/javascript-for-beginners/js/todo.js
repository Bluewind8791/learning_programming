
const todoForm = document.querySelector("#todo-form");
const todoInput = todoForm.querySelector("input");
const todoList = document.querySelector("#todo-list");
let todos = [];

const TODO_KEY = "@todoKey";


function saveTodoList() {
    localStorage.setItem(TODO_KEY, JSON.stringify(todos));
}

function deleteTodo(event) {
    const parentElement = event.target.parentElement;
    parentElement.remove();
    todos = todos.filter(item => item.id !== parseInt(parentElement.id));
    saveTodoList();
}

function initTodo() {
    const todolist = localStorage.getItem(TODO_KEY);
    if (todolist) {
        const json = JSON.parse(todolist);
        json.forEach(obj => {
            todos.push(obj);
            paintTodoList(obj);
        });
    }
}

function paintTodoList(obj) {
    const span = document.createElement("span");
    span.innerText = obj.text;

    const button = document.createElement("button");
    button.innerText = "❌";
    button.addEventListener("click", deleteTodo);

    const li = document.createElement("li");
    li.id = obj.id;
    li.appendChild(span);
    li.appendChild(button);
    todoList.append(li);
}

function handleTodoSubmit(event) {
    event.preventDefault();
    const text = todoInput.value;
    todoInput.value = ""; // clear input text
    const obj = {
        "id" : new Date().valueOf(),
        "text" : text,
    };
    todos.push(obj);
    saveTodoList();
    paintTodoList(obj);
}

initTodo();
todoForm.addEventListener("submit", handleTodoSubmit);
