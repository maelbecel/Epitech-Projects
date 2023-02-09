<template>
    <div class="LogIn">
        <Navbar />
        <div class="body">
            <img id="logo" alt="poodle logo" src="../../public/assets/poodle.png">
            <form method="get" :action="'/notes/' + encodeURIComponent(search)">
                <input id="search" type="text" placeholder="Search" v-model="search">
            </form>
        </div>
    </div>
</template>

<script>
import Navbar from '../components/Menu.vue'

export default {
  data () {
    return {
      search: ''
    }
  },
  components: {
    Navbar
  }
}
</script>

<style>
.header {
    padding-top: 1%;
    padding-bottom: 5%;
}

.body {
    padding-top: 7.5%;
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

#logo {
    position: relative;
    width: 40%;
    vertical-align: middle;
    margin-top: -10%;
}
#search {
    box-sizing: border-box;
    position: absolute;
    width: 35%;
    height: 5%;
    left: 32.5%;
    margin-top: 10%;
    border: 1px solid #4E5154;
    border-radius: 8px;
    padding: 15px;
}
</style>
