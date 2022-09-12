<template>
	<v-container v-if="initdone">
		<PnlWzskSesList
			v-on:request="handleRequest"
			ref="PnlWzskSesList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzskSesRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzskSesRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskSesList from './PnlWzskSesList';
	import PnlWzskSesRec from './PnlWzskSesRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskSes',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskSesList,
			PnlWzskSesRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskSes.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzskSes) this.continf = dpcheng.ContInfWzskSes;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskSes) this.statapp = dpcheng.StatAppWzskSes;
				if (dpcheng.StatShrWzskSes) this.statshr = dpcheng.StatShrWzskSes;
				if (dpcheng.TagWzskSes) {
					Wzsk.unescapeBlock(dpcheng.TagWzskSes);
					this.tag = dpcheng.TagWzskSes;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzskSesList.handleReply(obj);
					else this.$refs.PnlWzskSesRec.handleReply(obj);
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
					if (obj.srefIxWzskVDpch == "DpchEngWzskSesData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzskSesList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzskSesRec.handleUpdate(obj);
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
