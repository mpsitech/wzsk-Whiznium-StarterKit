<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Vision-to-rotary</h1>
		<PnlWzskVtrConfig
			v-on:request="handleRequest"
			ref="PnlWzskVtrConfig"
			:scrJref=statshr.scrJrefConfig
		/>
		<PnlWzskVtrMonitor
			v-on:request="handleRequest"
			ref="PnlWzskVtrMonitor"
			:scrJref=statshr.scrJrefMonitor
		/>
		<PnlWzskVtrDebug
			v-on:request="handleRequest"
			ref="PnlWzskVtrDebug"
			:scrJref=statshr.scrJrefDebug
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskVtrConfig from './PnlWzskVtrConfig';
	import PnlWzskVtrMonitor from './PnlWzskVtrMonitor';
	import PnlWzskVtrDebug from './PnlWzskVtrDebug';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskVtr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskVtrConfig,
			PnlWzskVtrMonitor,
			PnlWzskVtrDebug
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskVtr.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWzskVtr) this.continf = dpcheng.ContInfWzskVtr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskVtr) this.statapp = dpcheng.StatAppWzskVtr;
				if (dpcheng.StatShrWzskVtr) this.statshr = dpcheng.StatShrWzskVtr;
				if (dpcheng.TagWzskVtr) {
					Wzsk.unescapeBlock(dpcheng.TagWzskVtr);
					this.tag = dpcheng.TagWzskVtr;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefConfig) this.$refs.PnlWzskVtrConfig.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefMonitor) this.$refs.PnlWzskVtrMonitor.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefDebug) this.$refs.PnlWzskVtrDebug.handleReply(obj);
					else console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskVtrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefConfig) {
						this.$refs.PnlWzskVtrConfig.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefMonitor) {
						this.$refs.PnlWzskVtrMonitor.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefDebug) {
						this.$refs.PnlWzskVtrDebug.handleUpdate(obj);
						processed = true;
					}
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
