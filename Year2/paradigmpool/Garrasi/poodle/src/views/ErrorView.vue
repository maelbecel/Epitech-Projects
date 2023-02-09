<template>
    <div class="error">
        <div class="header">
            <img id="menu" src="../../../front/images/menu.webp" width="50" alt="Menu" v-on:click="$router.push({ name: 'index' })">
            <img id="icon" src="../../../front/images/profile.webp" width="60" alt="Menu" v-on:click="$router.push({ name: 'account' })">
        </div>
        <span class="display">
            <img src="../../../front/images/error.png" width="500" alt="Error">
        </span>
    </div>
</template>

<style>

.header {
    padding-top: 1%;
    padding-bottom: 5%;
}

#menu {
    float: left;
    margin-left: 1%;
}

#icon {
    float: right;
    margin-right: 1%;
}

.display {
    text-align: center;
    display: block;
}

</style>
