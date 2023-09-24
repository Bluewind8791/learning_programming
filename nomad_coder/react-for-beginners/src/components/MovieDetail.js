import React from "react";

function MovieDetail({ data }) {
    return (
        <div>
            <img src={data.medium_cover_image}  alt={data.title}/>
            <h2>{data.title}</h2>
            <p>Rating : {data.rating}</p>
            <p>Year : {data.year}</p>
            <p>Genres : </p>
            <ul>
                {data.genres.map(g => <li key={g}>{g}</li>)}
            </ul>
        </div>
    );
}
export default MovieDetail;