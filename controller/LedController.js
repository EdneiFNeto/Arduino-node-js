module.exports = {
    async index(request, response) {
    
        return response.json({
            nome:'Ednei'
        }, 201);
    },
}