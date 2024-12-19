fetch("https://blynk.cloud/external/api/get?token=HGwAXJ8VGOw15Tt8ge2vTjncMwYFt2lj&V0")
  .then((response) => {
    if (response.ok) {
      return response.text();  // Using .text() since the data returned is not in JSON format but just a value
    } else {
      throw new Error("NETWORK RESPONSE ERROR");
    }
  })
  .then(data => {
    console.log(data); // For debugging
    displayDistance(data);  // Call a function to display the distance
  })
  .catch((error) => console.error("FETCH ERROR:", error));

// Function to display the fetched distance in your HTML
function displayDistance(distance) {
    // Assuming you want to update the distance in a specific HTML element
    document.getElementById('distance-value').innerText = `${distance} cm`;
}
