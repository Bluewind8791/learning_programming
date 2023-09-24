import {useEffect, useState} from "react";

function App() {
    const [loading, setLoading] = useState(true);
    const [coins, setCoins] = useState([]);
    useEffect(() => {
        fetch("https://api.coinpaprika.com/v1/tickers")
            .then(res => res.json())
            .then(json => {
                setCoins(json);
                setLoading(false);
            });
    }, []);
    const [cash, setCash] = useState(0);
    const [coin, setCoin] = useState(0);
    const [coinPrice, setCoinPrice] = useState(0);
    function convert(event) {
        setCash(event.target.value);
        setCoin(cash / coinPrice);
    }

    function getSelected(event) {
        setCoinPrice(event.target.value);
        setCoin(cash / coinPrice);
    }

    return (
        <div>
            <div>
                <h1>The Coins!</h1>
                {loading ? (
                    <strong>Loading...</strong>
                ) : (
                    <select onChange={getSelected}>
                        <option key="blank" value="0">Please select...</option>
                        {coins.map(item =>(
                            <option key={item.id} value={item.quotes.USD.price}>
                                {item.name}({item.symbol}) : ${item.quotes.USD.price}
                            </option>
                        ))}
                    </select>
                )}
            </div>
            <div>
                <input
                    type="text"
                    onChange={convert}
                    value={cash}
                /> is {coin}
            </div>
        </div>
    );
}

export default App;
