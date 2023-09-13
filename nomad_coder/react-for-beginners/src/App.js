import {useState} from "react";

// #7.0, #7.1 To Do list
function App() {

    const [todo, setTodo] = useState("");
    function onChange(event) {
        setTodo(event.target.value);
    }

    const [todoList, setTodoList] = useState([]);
    function submit(event) {
        event.preventDefault();
        if (todo === "") return;
        setTodoList((curr) => [todo, ...curr]);
        setTodo("");
    }

    return (
        <div>
            <h1>My To Do List</h1>
            <form onSubmit={submit}>
                <input
                    type="text"
                    placeholder="Write your to do..."
                    value={todo}
                    onChange={onChange}
                />
                <button type="submit">Add</button>
            </form>
            <hr/>
            <ul>
                {todoList.map((todo, idx) => <li key={idx}>{todo}</li>)}
            </ul>
    </div>
  );
}

export default App;
