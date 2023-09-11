import Button from "./Button";
import styles from "./App.module.css";
import {useEffect, useState} from "react";

function App() {

    const [counter, setCounter] = useState(0);
    const onClick = () => setCounter((prev) => prev + 1);
    // called only one time
    useEffect(() => {
       console.log("i run only once");
    }, []);

    const [keyword, setKeyword] = useState("");
    const onChange = (event) => setKeyword(event.target.value);
    // called when keyword changed
    useEffect(() => {
        if (keyword !== "" && keyword.length > 5) {
            console.log("SEARCHING... ", keyword);
        }
    }, [keyword]);

    return (
        <div>
            <input
                type="text"
                onChange={onChange}
                value={keyword}
                placeholder="Search here..."
            />
            <h1 className={styles.title}>{counter}</h1>
            <button onClick={onClick}>Click me!</button>
        </div>
  );
}

export default App;
