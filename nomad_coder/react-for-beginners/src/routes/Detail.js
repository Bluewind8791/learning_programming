import {useParams} from "react-router-dom";
import {useEffect, useState} from "react";
import MovieDetail from "../components/MovieDetail";

function Detail() {
    const {id} = useParams();
    const [loading, setLoading] = useState(true);
    const [movieDtl, setDtl] = useState([]);
    const getMovieDetail = async () => {
        const json = await (
            await fetch(`https://yts.mx/api/v2/movie_details.json?movie_id=${id}`)
        ).json();
        setDtl(Array.of(json.data.movie));
        setLoading(false);
    }
    useEffect(() => getMovieDetail);

    return (
        <div>
            {loading ? <h1>Loading...</h1> : (
                <div>
                    {Array.isArray(movieDtl) ? movieDtl.map(dtl =>
                        <MovieDetail
                            key={dtl.id}
                            data={dtl}
                        />
                    ) : null}
                </div>
            )}
        </div>
    );
}
export default Detail;