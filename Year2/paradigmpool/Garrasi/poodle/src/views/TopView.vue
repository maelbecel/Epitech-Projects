<template>
  <div class="view">
    <Navbar />
    <div class="container">
      <div class="row">
        <img src="../../public/assets/vrai_poodle.png"  class="offset-4 col-4 my-5 py-5">
      </div>
      <div class="row">
        <h1 class="mb-5">Most Disliked Page</h1>
      </div>
      <div class="row">
        <div class="btn-group btn-group-lg col-6 offset-3" role="group">
          <input type="radio" class="btn-check" name="btnradio" id="btnradio1" autocomplete="off" checked>
          <label class="btn btn-outline-primary btn-lg" for="btnradio1">Weekly</label>
          <input type="radio" class="btn-check" name="btnradio" id="btnradio2" autocomplete="off">
          <label class="btn btn-outline-primary btn-lg" for="btnradio2">Monthly</label>
          <input type="radio" class="btn-check" name="btnradio" id="btnradio3" autocomplete="off">
          <label class="btn btn-outline-primary btn-lg" for="btnradio3">All Time</label>
        </div>
      </div>
      <div class="row">
        <div class="list-group col-6 offset-3 my-4">
          <button type="button" class="list-group-item list-group-item-action" v-for="(topic, i) in topics"
            :key="topic.name">
            <i class="fa-solid fa-crown" v-if="i == 0"></i><i :class="'fa-solid fa-' + (i + 1)" v-else></i> {{
              topic.name
            }}
          </button>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import Navbar from '../components/Menu.vue'

export default {
  data () {
    return {
      topics: [
        {
          name: 'https://intra.epitech.eu',
          value: 0
        },
        {
          name: 'https://www.youtube.com',
          value: 0
        },
        {
          name: 'https://www.google.com',
          value: 0
        },
        {
          name: 'https://www.facebook.com',
          value: 0
        },
        {
          name: 'https://www.reddit.com',
          value: 0
        }
      ]
    }
  },
  components: {
    Navbar
  }
}
</script>

<style scoped>

</style>
