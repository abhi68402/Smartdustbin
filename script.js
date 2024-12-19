// Function to fetch data from the API
async function fetchData() {
    const apiURL = 'https://blynk.cloud/external/api/get?token=HGwAXJ8VGOw15Tt8ge2vTjncMwYFt2lj&V0';

    try {
        const response = await fetch(apiURL);
        const data = await response.text();  // Assuming the response is plain text (a number in cm)

        // Update the distance value in the HTML
        document.getElementById('distance-value').innerText = `${data}`;  // Update the "distance" span

    } catch (error) {
        console.error('Error fetching data:', error);
        document.getElementById('distance-value').innerText = 'Error';
    }
}

// Fetch data immediately when the page loads
fetchData();

// Set interval to fetch data every 5 seconds (5000 milliseconds)
setInterval(fetchData, 5000);
